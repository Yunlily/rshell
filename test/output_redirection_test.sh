echo testing output redirection...
echo outputting readme to file newf
cat < ../README.md > newf
echo outputing comment test grep o to file newfile
cat < comment_test | grep o > newfile
echo newfile contents
cat < newfile
echo testing appending output redirection...
echo appending readme to file newf
cat < ../README.md >> newf
echo appending comment test grep o to file newfile
cat < comment_test | grep o >> newfile
echo newfile contents
cat < newfile
rm newf newfile
echo exiting...
exit

