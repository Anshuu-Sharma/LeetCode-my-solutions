# Write your MySQL query statement below
select e1.email as Email
from person e1
inner join person e2
on e1.id = e2.id
group by email
having count(*) > 1;