echo testing piping...
echo this should print the word count of this directory
ls | wc
echo grep a of this directory
ls | grep a
echo outputting grep a to file newf
ls | grep a > newf
echo double piping
ls | wc | tr a-z A-Z
echo pipe with input and output redirection
cat < newf | tr a-z A-Z | wc > newfile
echo pipe with input and appending output redirection
cat < newf | tr a-z A-Z | wc >> newfile
rm newf newfile
echo exiting...
exit
