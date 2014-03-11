set terminal post
set output "Majority_Error.ps"
set xlabel "Learning Rate"
set ylabel "error"
set datafile separator ' ' 
plot "Majority" u 1:3 with lines
