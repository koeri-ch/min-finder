void min_finder(std::vector<float> y, float threshold) {

    // extrema will contain the indices of 
    // the waveform vector that contain a minimum.
    std::vector<int> extrema;

    // N is the number of samples in
    // the waveform vector.
    int N = y.size();

    // We start at one sample after the 
    // beginning of the waveform.
    int i = 1; 
    while (i < N) {

        // We are going to compare the current sample i
        // to the ones ahead and before.
        int i_ahead = i + 1;
        int i_behind = i - 1;

        // Compare the current sample to the threshold
        // before determining the minima. This saves time.
        if (y[i] < threshold) {

            // Compare the current sample to all the following
            // and keep going, unless the ahead sample is different
            // than the current sample.
            while (y[i_ahead] == y[i] && i_ahead < N-1) {
                i_ahead++;
            }

            // Compare the sample ahead to the one before 
            // to find out if the current sample is a minimum.
            if (y[i_ahead]>y[i] && y[i_behind]>y[i] ) {
    
                // Find midpoint between ahead and before, 
                // or close to it. This will useful if the 
                // minimun is a plateau.
                int k = floor((i_ahead + i_behind)/2);
                extrema.push_back(k);
            }
        }
        
        // The show must go on.
        i++;
    } 

    // Return the vector to the caller.
    return extrema;       
}