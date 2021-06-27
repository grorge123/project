FROM python:3.8.8-buster

WORKDIR /app

COPY requirements.txt .
RUN pip install -r requirements.txt
RUN apt-get update -qq && apt-get install -qq libfluidsynth1 fluid-soundfont-gm build-essential libasound2-dev libjack-dev
COPY . .

EXPOSE 8501

CMD ["streamlit", "run", "main.py"]
