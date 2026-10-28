select u.unique_id, e.name
from EmployeeUNI as u
right join Employees as e on u.id = e.id