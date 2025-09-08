# Write your MySQL query statement below
select v.customer_id, count(v.visit_id) as count_no_trans from Visits v
left join Transactions t on t.visit_id=v.visit_id
# Keeps only those visits without any matching transaction (i.e., customer visited but didn’t buy anything).
where t.transaction_id is null
# Groups by customer, so you get one row per customer with their count of non-transaction visits.
group by v.customer_id
