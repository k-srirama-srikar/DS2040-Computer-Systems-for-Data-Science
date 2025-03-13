# Set title and labels
set title "Cache Misses vs Block Size"
set xlabel "Block Size"
set ylabel "D1 Cache Misses"

# Set the output format (optional, for saving the plot as a PNG image)
set terminal pngcairo enhanced
set output 'cache_misses.png'

# Plot the data
plot "cache_misses.txt" using 1:2 with linespoints title 'D1 Cache Misses'

