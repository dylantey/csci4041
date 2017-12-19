-assumption is that maxsize is maxsize = 100000, if different string length, it would be compared as if the ends were added with 'z's, meaning Kaa < Ka
-totalChar is the number of buckets where it is initially set to 26, one bucket for each alphabet
-names in file will be parsed into str1 array
-bucketMax is the maximum number of elements of each bucket which is 10
-beginBucket and endBucket are used to identify the starting and ending index of an alphabet, especailly when there's more than 1 bucket for an alphabet
-if bucket is full, and there's an attempt to add another one, bool NewBucket will be triggered which would be used later on to move indexes of the array to create an extra bucket
-charListOption array holds the starting character of the string, initally A-Z, 26 elements, but would be expanded when an extra bucket is need
-when there's more than one bucket (>10 elements), the element wanting to be added would first be added and then every element of the character (in multiple buckets) would ALL be popped out into an array, sorted, then pushed back into the bucket



