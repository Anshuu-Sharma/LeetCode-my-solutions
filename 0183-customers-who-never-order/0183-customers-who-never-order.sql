# Write your MySQL query statement below
select c.name as Customers
from Customers c
left join orders o
on c.id = o.customerId
where o.customerId IS null;

