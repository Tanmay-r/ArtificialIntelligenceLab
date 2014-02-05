set terminal post
set output "output1.ps"
set xlabel "w[i]"
set ylabel "iteration"
set datafile separator ',' 
plot "1.txt" u 1:2 with lines
