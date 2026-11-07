# TAISO

Taiso is a portable 2-octave digital synthesizer.

currently working to ship to Hack Club PHANTOM.

lil demo:       
- https://wokwi.com/projects/480036402492236801     
- https://youtu.be/BU_JOI64sTc

# Overview
You can't live without art; if you say you don't then you either don't know what Art means, or you have a miserable life. Art isn't just paintings or music - it's also everything else around you, from cars & buildings to your clothing. - 

Regardless of your accessibility & connection to art, everyone should have the *option* to make art. I want it to be as accessible as possible so I made TAISO. I want both a grumpy right-wing 70 y/o, AND a random kid in a different continent to be able to make art. In art; I know the most about music. I also happen to be an engineer, so I hope I'm using my skills for good.

# Architecture
TAISO is based off the Teensy 4.1 combined with the PJRC Teensy Audio shield D. , in tandem with the PAM8403 Amplifier.
My initial teensy & its replacement fried for reasons outside of my capability, so I switched to Arduino Nano's as a last ditch effort.
thus, there are 2 versions of the architecture; Teensy 4.1 based & Arduino Nano based.

TAISO works by doing digital sound generation. Essentially, an input triggers the chip, and an initial number is created. That number goes through many complicated math formulas every second; like every filter you apply to the sound changes its profile a bit. Every little change is applied to the digital sound as a mathematical formula,, whether that's multiplication or something much more complicated.
Some basic ones are Attack, Sustain, Decay, Release. about 20,000 times/s, (or every electrical "tick"), the generated sound is multiplied by the current value of A,D,S,R and as you do that over 5 seconds; outputting a lower and lower number as sound it sounds like a slowly decreasing, smooth note. (Lower and lower is only for Release, A-D-R give different effects ontop of that if enabled.)
That multiplied number gets transformed into electrical output in Voltage, gets amplified and is sent to the speakers to create sound.

# Hardware
Inputs: Switch matrix (5x5 gateron milkys) + 1 more switch for ui, Knobs (b10k pots)
Outputs: 2x 5W 8ohm spaeakers (salvaged from old radio)

the switch matrix has diodes soldered to prevent ghosting, and i put it in a matrix specifically to save on IO.

The speakers (wired as r+, r-, l+, l-) are wired to the PAM8403 module (aka Amp/Amplifier) The amp gets input from the teensy thru pins R,L,G. Lines R & L have inline capacitors on them to minimize signal interference (104J100, doesn't really matter.)

power system: Currently running off a USB cable; requires stable 5 - 5.3v PSU. (phone charger, powerbank or PC, etc.)
I made a portable power system that runs off a 18650 3.7V battery, paired with TP4056 charging unit for USB-C and a voltage booster module but the voltage booster ended up being defective so I couldn't attach the power management system in time. TAISO requires usb power for now.

# Demos
This demo was made with the arduino nano config.
-youtube link

# What went wrong..
I had to go to a robotics competition on 30/10 (friday) so i rushed to finish TAISO's MVP by thursday night. As I was uploading code after being %100 done with soldering, my Teensy fried (and the shield on it). I was heartbroken because it was like less than 10 seconds until the end; i wasn't even touching the circuit at that point.

Friday comes, I'm thinking to myelf like "damn I HAVE to get a replacemnt Teensy today" so I sneak out on lunch break to take a train 2 hours north in pouring rain, without telling my teacher. I go the office of this robotics company and i get my order that I had placed earlier. Mission accomplished, i think to myself. (foreshadowing)

I skip lunch and arrive an hour or two late, nobody realises i'm gone; its fine. I get home that evening at about 8 PM (awake since 7AM that day), i realise theres about 10 hours until Stardance is going to end (it was ending at 7AM Saturday for me.); I decide i'm not going to sleep and i'll finish it. Even though the robotics comp is still going, it'd still be a saturday anyway.

9, 10, 11, PM comes and goes, many hours pass; I'm locked in so hard I didn't realise i sat on my ass and worked until 5 AM. I hear the birds chirping out my window and i realise i have little time left so I hurry up a little bit.
6 AM comes, everything is done. I turn it on, and nothing is happening; the teensy's power indicator is not turning on.
Some stuff happens, long story short the replacement teensy was defective from manufacturing.

I go to sleep defeated and make a sad devlog about it on stardance (i'm going to sleep at 7AM btw)
at like 8 am i hear a noise, stardance got extended 12 hours! I rush to finish it. I try to replace the teensy's with whatever i can; i can't buy another one at that point. I replaced it with an Arduino Nano. Both of those fried before i was %100 done.

The story is useless though; what matter is WHAT DID I LEARN?
if you're buying an expensive chip, upload the code in it before you wire literally anything.
carry high quality data+power cables you know FOR SURE work.
don't get flux inside an SD card port.
don't immediately solder headers on a new chip.
check for GND-power pin short (VIN, 5V, 3.3V, whatever) before testing every major change and solder.
if you suspect a card is fried, don't try to power it up again; you'll burn your hands.


# useless background info (these were written a long time ago)
Everybody in my generation knows that they're killing their own potential by constantly looking at their phones. I present Taiso as the alternative. Designed to make real music accessible without the judgement of social media, without being led into subscriptions and without having to spend hundreds of hours infront of a computer. I don't have access to a synthesizer, and I don't think FL studio and cracked plugins are the future of composition. This is my answer.
# Why I built this
I wanted to create something that could atleast replicate the feeling of being in one of those rooms that has a massive wooden desk with like.. a thousand tracks on it and a slider for each one. I don't know. I've never been in one. Nor do I know its name. But I know that there are people who've been making music for 50 years and are now unable to use those because they simply cannot compete when there's plugins, cracked FL studio's, a million beatmakers on youtube, you get the point. I want the whatever teenager in some unknown country (people like me basically) to be able to use, feel and know what it feels to use a real synthesizer. The closest one to me is an hour away, I literally have to cross a continent to get there, and there's a worker literally protecting the machine 24/7 and it's unplugged anyway. I don't blame them ofcourse, the machine DOES cost 10,000$+ after all, but it means that I will probably never get to use it unless I'm 40 years old or beat thousands of other ambitious people in a race of "success". I knew there had to be a way, and basically; acting like it's analog is the answer, apparently. Here is Taiso.
# About the builder
i'm from turkey. i grew up with a conservative muslim family, and because of my brother's lead and influence, i found a way to differentiate myself from my 20 or so cousins that live the exact same life. in the middle of a family that didn't even think of art, i somehow grew up listening to daft punk; my guess is that it affected me so much because it was radically different than what i saw every day. these songs and the people who made them shaped the way i think about life, and taught me to not care. to do what I want. i want to show people like me, even if they didn't have a brother like mine; what's out there.


























Inspired by the minimoog. Dedicated to Giorgio Moroder and Murat Özdil.
