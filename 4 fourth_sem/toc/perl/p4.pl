# Question: Write a Perl program that matches a pattern in a string and displays the text before, the matched part, and the text after the match.


#example pattern matching three operators  
$string = "aabbbaabbbabab";
$string =~ m/aba/;
print "Befor:$`\n"; # To print before by text
print "Match:$&\n"; # To print exact match of text 
print "After:$'\n"; # To print after match
