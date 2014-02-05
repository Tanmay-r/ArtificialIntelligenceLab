set terminal post
set output "output1.ps"
set yrange [0.256442975:0.256442976]
set xlabel "iteration"
set ylabel "error"
set datafile separator ',' 
plot "output2" u 1:2 with lines
