# Set title and labels
set title "Blocked Transpose Time vs Block Size"
set xlabel "Block Size"
set ylabel "Time (seconds)"

# Set the output format (optional, for saving the plot as a PNG image)
set terminal pngcairo enhanced
set output 'blocked_transpose.png'

# Plot the data
plot "transpose_times.txt" using 1:2 with linespoints title 'Blocked Transpose'

