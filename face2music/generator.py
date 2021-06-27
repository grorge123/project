import magenta.music as mm
from magenta.models.music_vae import configs
from magenta.models.music_vae.trained_model import TrainedModel
import os
import tensorflow.compat.v1 as tf
import random

PWD = os.getcwd()

def interpolate(model, start_seq, end_seq, num_steps, max_length=32,
                assert_same_length=True, temperature=0.5,
                individual_duration=4.0):
    """Interpolates between a start and end sequence."""
    note_sequences = model.interpolate(
        start_seq, end_seq,num_steps=num_steps, length=max_length,
        temperature=temperature,
        assert_same_length=assert_same_length)
    interp_seq = mm.sequences_lib.concatenate_sequences(
        note_sequences, [individual_duration] * len(note_sequences))
    mm.plot_sequence(interp_seq)
    return interp_seq if num_steps > 3 else note_sequences[num_steps // 2]

trio_models = {}
hierdec_trio_16bar_config = configs.CONFIG_MAP['hierdec-trio_16bar']
trio_models['hierdec_trio_16bar'] = TrainedModel(hierdec_trio_16bar_config, batch_size=4, checkpoint_dir_or_path= './checkpoints/hierdec-trio_16bar.ckpt')


def generage(mu):
    print("FIND:", mu)
    input_trio_midi_data = [
    tf.io.gfile.GFile(fn, 'rb').read()
    for fn in sorted(tf.io.gfile.glob(PWD + mu + '*.mid'))]
    input_trio_midi_data.append(tf.io.gfile.GFile(tf.io.gfile.glob(PWD + '/music/' + "hierdec_trio_16bar_mean.mid")[0], 'rb').read())
    base = tf.io.gfile.glob(PWD + '/music/' + "hierdec*.mid")
    random.shuffle(base)
    for i in range(random.randint(0, len(base) - 1)):
        input_trio_midi_data.append(tf.io.gfile.GFile(base[i], 'rb').read())
    trio_input_seqs = [mm.midi_to_sequence_proto(m) for m in input_trio_midi_data]
    extracted_trios = []
    for ns in trio_input_seqs:
        extracted_trios.extend(
            hierdec_trio_16bar_config.data_converter.from_tensors(
                hierdec_trio_16bar_config.data_converter.to_tensors(ns)[1]))

    trio_interp_model = "hierdec_trio_16bar" #@param ["hierdec_trio_16bar", "baseline_flat_trio_16bar"]

    print("LEN:",len(extracted_trios))
    if(len(extracted_trios)<=1):
        return generage(mu)
    start_trio = 0 #@param {type:"integer"}
    end_trio = random.randint(1, len(extracted_trios) - 1) #@param {type:"integer"}
    start_trio = extracted_trios[start_trio]
    end_trio = extracted_trios[end_trio]

    temperature = 0.5 #@param {type:"slider", min:0.1, max:1.5, step:0.1}
    trio_16bar_mean = interpolate(trio_models[trio_interp_model], start_trio, end_trio, num_steps=3, max_length=256, individual_duration=32, temperature=temperature)

    return trio_16bar_mean