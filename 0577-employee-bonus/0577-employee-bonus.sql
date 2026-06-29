# Write your MySQL query statement below
select name, bonus
from Employee e
left join Bonus b
on e.empID = b.empID
where bonus < 1000 || bonus is NULL;