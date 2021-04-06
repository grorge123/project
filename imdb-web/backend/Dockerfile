
FROM python:3.8.8-buster

WORKDIR /app

RUN apt-get update
# RUN apt-get install \
#     'ffmpeg'\
#     'libsm6'\
#     'libxext6'  -y

COPY requirements.txt .
RUN pip install -r requirements.txt

RUN pip install torch==1.8.1+cpu torchvision==0.9.1+cpu torchaudio==0.8.1 -f https://download.pytorch.org/whl/torch_stable.html

COPY . .

EXPOSE 8080

CMD ["python", "main.py"]
