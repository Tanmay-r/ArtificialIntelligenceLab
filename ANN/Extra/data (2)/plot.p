set terminal post
set output "Palindrome_epoch_error_M=0.9_eta=0.2.ps"
set xlabel "Iteration Number"
set ylabel "error"
set datafile separator ' ' 
plot "Palindrome_M=0.9_eta=0.2" u 3:4 with lines
