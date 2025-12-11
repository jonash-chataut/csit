# Question: Write a Perl program that takes a string as input and checks whether it contains the pattern "ab".


#!C:\Perl64\bin\perl.exe
#input from user example

print "Enter your string :";
$string = <STDIN>;
if($string =~m[ab]{
print"\nPattern matched in the string";
}else {
	print"\n pattern not matched";
}