import torch
from transformers import BertTokenizer
from torch.nn.utils.rnn import pad_sequence

PRETRAINED_MODEL_NAME = "bert-base-uncased"


def inference(model, text):
    pass
    tokenizer = BertTokenizer.from_pretrained(PRETRAINED_MODEL_NAME)
    word_pieces = ["[CLS]"] + tokenizer.tokenize(text)
    token = torch.tensor(tokenizer.convert_tokens_to_ids(word_pieces))
    tokens_tensor = [token]
    tokens_tensors = pad_sequence(tokens_tensor, batch_first=True)
    masks_tensors = torch.zeros(tokens_tensors.shape, dtype=torch.long)
    masks_tensors = masks_tensors.masked_fill(tokens_tensors != 0, 1)
    outputs = model(input_ids=tokens_tensors, attention_mask=masks_tensors)
    _, pred = torch.max(outputs[0], 1)
    return int(pred[0])