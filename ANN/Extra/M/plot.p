set terminal post
set output "Majority_Momentum.ps"
set xlabel "Momentum"
set ylabel "epoch number"
set datafile separator ' ' 
plot "Majority_Momentum" u 1:2 with lines
