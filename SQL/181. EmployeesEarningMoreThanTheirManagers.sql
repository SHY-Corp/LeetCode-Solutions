Select a.Name as Employee                 /* Selecting column and renaming it */
from Employee as a join employee as b     /* Self join using 2 different names */
on a.ManagerId=b.Id                       /* Join condition */
and a.Salary>b.Salary;                    /* Condition for selecting records */
