select e.name, b.bonus
from bonus as b
right join employee as e 
ON e.empid = b.empid
where bonus < 1000 OR bonus is NULL