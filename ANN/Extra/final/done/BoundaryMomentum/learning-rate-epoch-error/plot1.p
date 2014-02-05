set terminal post
set output "LearningRate-Epoch-Majority.ps"
set xlabel "Learning rate"
set ylabel "Epoch"
set datafile separator ' ' 
plot "Majority" u 1:2 with lines
