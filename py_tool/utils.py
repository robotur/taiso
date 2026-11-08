#backend stuff for the tool

from tkinter import messagebox
import wave
import json
import os
import shutil

def get_wav_info(file_path):
    try:
        with wave.open(file_path, 'rb') as w:
            frames = w.getnframes()
            rate = w.getframerate()
            duration = frames / float(rate)
            return duration, rate
    except Exception:
        return None, None

def export_loop_to_sd(wav_src, sd_dir, bpm, bars):
        duration, sample_rate = get_wav_info(wav_src)

        if not duration:
            raise ValueError("Could not read .wav file's properties.")

        total_samples = int(duration * sample_rate)
        base_name = os.path.basename(wav_src)
        name_no_ext = os.path.splitext(base_name)[0]

        sidecar_data = {
            "name": name_no_ext,
            "bpm": bpm,
            "bars": bars,
            "sample_rate": sample_rate,
            "total_samples": total_samples,
            "duration": duration
        }

        dest_wav = os.path.join(sd_dir, base_name)
        dest_json = os.path.join(sd_dir, f"{name_no_ext}.json")

        shutil.copy(wav_src, dest_wav)
        with open(dest_json, 'w') as f:
            json.dump(sidecar_data, f, indent = 4)



    
    