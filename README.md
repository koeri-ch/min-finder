# min-finder

This little project had the objective to find the negative pulses in a signal. It finds the minima that are below a certain threshold, being very fast on that. It is based on SciPy's peak-finding function, but it is different in two ways: it finds minima instead of maxima; and only applies the pulse-finding algorithm in parts of the waveform that are smaller than a threshold. The latter is responsible for making this function really fast, as it only applies the minimun-finding algorithm in the regions of the waveform which most likely contain the pulse we want. 

## How it works

This function is based on SciPy Signal's peak-finding function, but tweaked to find minima instead of maxima. It works by taking samples of a waveform and, as it moves forward along the waveform samples, compares the current one to all the succeding samples. When the first different succeding sample is found, it will compare the current sample with that one ahead and with the one immediately before, classifying the current sample as a minimum or not. However, while SciPy's function is much more robust and complete, min-finder only cares about the pulse height; it will firstly find the regions of the waveform that are below a certain threshold and apply the minimum-finding algorithm that such regions. This has the advantage of applying the algorithm only to a small size of the waveform, hence achieving faster performance.

## How to use it

A vector containing the waveform should be passed to the min-finder function, along with a scalar value for the treshold. The function will return a vector containing the indices of the waveform vector which represent the minima.

The two folders, named *cpp* and *python*, will contain the function for each of the languages, respectively. 

## References

Please refer to the SciPy's [documentation](https://docs.scipy.org/doc/scipy/reference/generated/scipy.signal.find_peaks.html) and [source code](https://github.com/scipy/scipy/blob/master/scipy/signal/_peak_finding.py).
