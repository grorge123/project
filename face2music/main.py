import json
import requests
import streamlit as st
from PIL import Image
import facedec
from scipy.io import wavfile
import pretty_midi
import numpy as np
import io
from generator import generage
import midi_io
from scipy.io.wavfile import write

# https://discuss.streamlit.io/t/version-0-64-0-deprecation-warning-for-st-file-uploader-decoding/4465
st.set_option("deprecation.showfileUploaderEncoding", False)

# defines an h1 header
st.title("face2music")

# displays a file uploader widget
image = st.file_uploader("Choose an image")

# displays the select widget for the styles
# style = st.selectbox("Choose the style", [i for i in STYLES.keys()])
text = ''
# text = st.text_input('Enter some text')

# displays a button
if st.button("check"):
    if image != None:
        ge = facedec.reqfaced(image)
        if len(ge) != 0:
            emotion = ['anger', 'happiness', 'sadness', 'disgust']
            prabability = []
            for i in emotion:
                prabability.append(ge[0]['faceAttributes']['emotion'][i])
            st.text(emotion[prabability.index(max(prabability))])
            music_path = "./music/"
            # audio_file = open(music_path + emotion[prabability.index(max(prabability))] + '.mp3', 'rb')
            tn = "anger"
            if text != None and len(text) != 0:
                tn = text
                audio_file = open(music_path + tn + '.mid', 'rb')
                midi_data = pretty_midi.PrettyMIDI(audio_file)
            else:
                audio_file = generage(emotion[prabability.index(max(prabability))])
                midi_data = midi_io.sequence_proto_to_pretty_midi(audio_file)
            audio_data = midi_data.fluidsynth()
            audio_data = np.int16(
                audio_data / np.max(np.abs(audio_data)) * 32767 * 0.9
            )  # -- Normalize for 16 bit audio https://github.com/jkanner/streamlit-audio/blob/main/helper.py

            virtualfile = io.BytesIO()
            wavfile.write(virtualfile, 44100, audio_data)
            write("example.wav", 44100, audio_data)
            st.audio(virtualfile)
            # audio_bytes = audio_file.read()
            # st.audio(audio_bytes, format='audio/wav')
        else:
            st.text("Can not detect face")
