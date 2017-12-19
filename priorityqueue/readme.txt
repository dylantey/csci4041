-file is parsed into inputName, delim(not used), and InputInt, the data is inserted into bank queue while reading data in file
-queue (singly linked list) is always max to min
-if there's no node in queue, insert into front, or if the data wanting to be inserted is GREATER than the FRONT node, it will be inserted in front
-else it will find a spot in the queue that satisfy the condition of the node in front is greater than itself and the node at the back is smaller

-caution: had a problem with the input of the file in Windows. it was Paul : 2
Alan : 5
Adrienne : 8
Agnessa : -1
Lilian : 9001
Yehonatan : 5
Yehonatan : -5

-professor said it's a problem with the Windows newline being different from Linux
-with the input file being spaced correctly, it works fine
i.e.
Paul : 2

Alan : 5

Adrienne : 8

Agnessa : -1

Lilian : 9001

Yehonatan : 5

Yehonatan : -5
