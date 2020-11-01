# Write your MySQL query statement below
# Logic - Joined all the three tables using self join and used DISTINCT to removed duplicates.
# Alias Named all the three logs tables as l1, l2, l3 respectively.

SELECT DISTINCT l1.Num AS ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3
WHERE l1.Id = l2.Id - 1 AND l2.Id = l3.Id - 1 AND l1.Num = l2.Num AND l2.Num = l3.Num;

