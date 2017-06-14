
echo printing files
echo COMMENT TEST
cat < comment_test
echo README
cat < ../README.md
echo piping to word count
cat < comment_test | wc
echo piping to grep i
cat < comment_test | grep i
echo piping to tr
cat < comment_test | tr a-z A-Z
echo exiting...
exit
