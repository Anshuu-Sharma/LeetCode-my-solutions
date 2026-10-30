select e.name, b.bonus
from employee as e
left join bonus as b
ON e.empid = b.empid
where bonus < 1000 OR bonus is NULL