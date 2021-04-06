import uuid

import torch
import uvicorn
from fastapi import File
from fastapi import FastAPI
from fastapi import UploadFile
import numpy as np
from pydantic import BaseModel

import inference

class Item(BaseModel):
    text: str

app = FastAPI()


@app.get("/")
def read_root():
    return {"message": "Welcome from the API"}


@app.post("/check")
def get_text(item: Item):
    model = torch.load('./models/imdb_bert.pth', map_location=torch.device('cpu'))
    output = inference.inference(model, item.text)
    return output


if __name__ == "__main__":
    uvicorn.run("main:app", host="0.0.0.0", port=8080)
