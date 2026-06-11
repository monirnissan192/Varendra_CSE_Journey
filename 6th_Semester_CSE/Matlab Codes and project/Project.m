% 1. Define Sampling Rate and Time (10 seconds)
Fs = 256; 
t = 0:1/Fs:10; 

% 2. Create the artificial EEG signal (10 Hz) and noise (50 Hz)
eeg_wave = 0.5 * sin(2*pi*10*t);
noise = 0.2 * sin(2*pi*50*t);
raw_signal = eeg_wave + noise;

% 3. Format the data for Simulink
simin = [t', raw_signal'];