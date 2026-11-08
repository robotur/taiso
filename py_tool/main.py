import tkinter as tk
from tkinter import filedialog, messagebox, ttk
import wave
import os

#this file lets you pick an sd card and a .wav file, the bpm and bar length, then it creates a folder on the sd card with the proper formatting so TAISO can use it.
#UI PORTION OF THE CODE IS IN THIS FILE, BACKEND STUFF IS IN utils.py

from utils import get_wav_info, export_loop_to_sd

class TaisoAssetPrep: #set window parameters
    def __init__(self, root):
        self.root = root
        self.root.title("TAISO loop asset prep")
        self.root.geometry("600x400")
        self.root.resizable(False, False)

        self.wav_path = tk.StringVar()
        self.sd_path = tk.StringVar()
        self.bpm_val = tk.StringVar(value="120")
        self.bars_val = tk.StringVar(value="4")

        icon_path = os.path.join(os.path.dirname(__file__),"..","assets", "taiso.ico")
        if os.path.exists(icon_path):
            self.root.iconbitmap(icon_path)
        else:
            print("Icon file not found. Continuing without custom icon.")
        
        self.build_ui()

    def build_ui(self): #create buttons & labels
        ttk.Label(self.root, text="TAISO asset prep", font=("Arial",14,"normal")).pack(pady = 12)

        ttk.Button(self.root, text = "1. select .wav file", command = self.pick_wav).pack(fill = "x", padx = 25, pady = 4)
        ttk.Label(self.root, textvariable=self.wav_path, foreground ="gray",wraplength = 400).pack()

        ttk.Button(self.root, text = "2. select SD mount directory", command = self.pick_sd).pack(fill = "x", padx = 25, pady = 4)
        ttk.Label(self.root, textvariable=self.sd_path, foreground ="gray",wraplength = 400).pack()

        frame_grid = ttk.Frame(self.root)
        frame_grid.pack(pady = 15)

        ttk.Label(frame_grid, text="BPM: ").grid(row=0, column=0, padx=6, pady = 5)
        ttk.Entry(frame_grid, textvariable=self.bpm_val, width = 8).grid(row = 0, column = 1, padx=6, pady = 5)

        ttk.Label(frame_grid, text="Bar length: ").grid(row=0, column=2, padx=6, pady = 5)
        ttk.Entry(frame_grid, textvariable=self.bars_val, width = 8).grid(row = 0, column = 3, padx=6, pady = 5)

        #export button
        ttk.Button(self.root, text = "EXPORT TO SD CARD", command = self.export_to_sd).pack(fill = "x", padx = 25, pady = 15)

        ttk.Label(self.root, text="made by musti for hc phantom. <3 19560625", foreground ="gray",wraplength = 400).pack(side="bottom")


    #file dialogues
    def pick_wav(self): 
        path = filedialog.askopenfilename(filetypes=[("WAV files", "*.wav")])
        if path:
            self.wav_path.set(path)

    def pick_sd(self):
        path = filedialog.askdirectory(title="Select SD card drive/folder")
        if path:
            self.sd_path.set(path)


    #self explanatory; takes all info inputted from before and writes to SD
    def export_to_sd(self):
        wav_src = self.wav_path.get()
        sd_dir = self.sd_path.get()

        if not wav_src or not sd_dir:
            messagebox.showerror("Error", "Please select both a .wav file and an SD card directory.")
            return

        try:
            bpm = float(self.bpm_val.get())
            bars = int(self.bars_val.get())
        except ValueError:
            messagebox.showerror("Error", "BPM must be a number and Bar length must be an integer.")
            return

        try:
            export_loop_to_sd(wav_src, sd_dir, bpm, bars)
            messagebox.showinfo("Success", f"Exported successfully to SD card.")
        except Exception as e:
            messagebox.showerror("Error", str(e))

if __name__ == "__main__":
    root = tk.Tk()
    app = TaisoAssetPrep(root)
    root.mainloop()