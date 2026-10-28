select Distinct(v.customer_id), count(v.visit_id) as count_no_trans
from Transactions as t
right join visits as v
ON v.visit_id = t.visit_id
where t.transaction_id IS NULL
group by v.customer_id