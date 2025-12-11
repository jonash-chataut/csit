# Question: Write a Perl program that performs pattern matching on a string and prints the text before, the matched text, and the text after the match.

# example pattern matching three operators  
$string = "Due to covid-19 Fifth semester students in online";
$string =~ m/Fifth/;
print "Befor:$`\n"; # To print before by match text[fifth]
print "Match:$&\n"; # To print exact match of text 
print "After:$'\n"; # To print after match