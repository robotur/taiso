# Taiso Hybrid Analog Synthesizer

Taiso is a portable 2-octave hybrid analog synthesizer.

# Overview

Everybody in my generation knows that they're killing their own potential by constantly looking at their phones. I present Taiso as the alternative. Designed to make real music accessible without the judgement of social media, without being led into subscriptions and without having to spend hundreds of hours infront of a computer. I don't have access to a synthesizer, and I don't think FL studio and cracked plugins are the future of composition. This is my answer.

# How it works

Hybrid analog means the sound created is Digital, it gets converted into analog and can be manipulated like an analog signal. Basically means the sound profile is very similar to a classic synthesizer, the filtration step of the sound is exactly the same as those big Moog synthesizers, the only difference being it's more stable because there isn't actually thousands of resistors and capacitors creating the sound, in its core it's a raspberry pi instead. Arguably worse, but definitely better considering cost.

# Controls

There's 8 knobs for controlling volume;
1-4: ADSR (directly controls raspi output)
6-7: Cutoff & resonance (controls the output of DAC)

 - Attack
 - Decay
 - Sustain
 - Release
 - Cutoff
 - Resonance
 - Master Volume
 - Custom (empty)

2 buttons for scrolling up-down octaves,

5 buttons for layering sounds;
Record,
Delete,
Layer 1 - Layer 2 - Layer 3. (If recording, switches to the layer / If full, turns on-off loop of recording)
Layer activations are synced with BPM to make timing easier.

Record button remembers whatever order of keys you pressed and its sound profile to be looped until pressed again.
Delete cleans the layer you're on. Holding down Delete cleans all 3 layers.

Display: The display shows the soundwave of whatever sound is being exported. Will layer 3 different soundwaves if there are multiple layers active.

# Current development stage

Rough CAD model done and a part of the power lines are done in the schematic.

# What's next?
Funding will allow me to move RB from schematics to a working prototype. I'm going to get the physical body as quickly as I can and move onto the PCB, making sure that it will fit, testing any electrical connections as a final check and ordering the necessary parts. When the pcb arrives, assembly and soldering will be made, and Taiso will be ready for testing.

Future:
I want to add more features like vocal sampling with a microphone, more layers, ability to add drums (with drumpads maybe), more usability for the screen.
In the future I definitely want to make a piece of software that connects to RB and allows you to make something like those DJ/Concert backgrounds from what you're playing, send it to a monitor for live or export as video file. I'm thinking about a 3 octave model too, but I need anodized aluminum, and a cnc machine to make the body for that.

# Why I built this

I wanted to create something that could atleast replicate the feeling of being in one of those rooms that has a massive wooden desk with like.. a thousand tracks on it and a slider for each one. I don't know. I've never been in one. Nor do I know its name. But I know that there are people who've been making music for 50 years and are now unable to use those because they simply cannot compete when there's plugins, cracked FL studio's, a million beatmakers on youtube, you get the point. I want the whatever teenager in some unknown country (people like me basically) to be able to use, feel and know what it feels to use a real synthesizer. The closest one to me is an hour away, I literally have to cross a continent to get there, and there's a worker literally protecting the machine 24/7 and it's unplugged anyway. I don't blame them ofcourse, the machine DOES cost 10,000$+ after all, but it means that I will probably never get to use it unless I'm 40 years old or beat thousands of other ambitious people in a race of "success". I knew there had to be a way, and basically; acting like it's analog is the answer, apparently. Here is Taiso.

# About the builder

i'm from turkey. i grew up with a conservative muslim family, and because of my brother's lead and influence, i found a way to differentiate myself from my 20 or so cousins that live the exact same life. in the middle of a family that didn't even think of art, i somehow grew up listening to daft punk; my guess is that it affected me so much because it was radically different than what i saw every day. these songs and the people who made them shaped the way i think about life, and taught me to not care. to do what I want. i want to show people like me, even if they didn't have a brother like mine; what's out there.


























Inspired by the minimoog. Dedicated to Giorgio Moroder and Murat Özdil.
