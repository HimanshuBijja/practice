
-- ========== INSERT OPERATIONS ==========

-- Insert Users
INSERT INTO users (user_id, first_name, last_name, email, phone_number, date_of_birth) VALUES
(1, 'Devi', 'Ganesh', 'devi.ganesh@email.in', '+91-9876543210', '2001-02-15'),
(2, 'Aum', 'Singh', 'aum.singh@email.in', '+91-9876543211', '2002-06-10'),
(3, 'Manoj', 'Yadav', 'manoj.yadav@email.in', '+91-9876543212', '2003-09-05'),
(4, 'Himanshu', 'Bijja', 'himanshu.bijja@email.in', '+91-9876543213', '2001-12-22');

-- Insert Accounts
INSERT INTO accounts (account_id, user_id, account_number, balance) VALUES
(101, 1, 'ACC001234567890', 5000.00),
(102, 1, 'ACC001234567891', 1500.00),
(103, 2, 'ACC002234567890', 3200.50),
(104, 3, 'ACC003234567890', 7500.75),
(105, 4, 'ACC004234567890', 2100.25);

-- Insert Transactions
INSERT INTO transactions (transaction_reference, sender_account_id, receiver_account_id, amount, status) VALUES
('TXN001', 101, 103, 500.00, 'completed'),
('TXN002', 103, 104, 1200.00, 'completed'),
('TXN003', 104, 105, 300.50, 'pending'),
('TXN004', 105, 101, 750.00, 'completed'),
('TXN005', 102, 103, 1000.00, 'completed'),
('TXN006', 101, 104, 2500.00, 'cancelled');

-- ========== UPDATE OPERATIONS ==========

-- Update user information
UPDATE users 
SET email = 'devi.ganesh.updated@email.in', phone_number = '+91-9876543219' 
WHERE user_id = 1;

-- Update account balance after transaction
UPDATE accounts 
SET balance = balance - 500.00 
WHERE account_id = 101;

-- Update multiple transactions status
UPDATE transactions 
SET status = 'completed' 
WHERE status = 'pending' AND amount < 1000.00;

-- Update user's date of birth
UPDATE users 
SET date_of_birth = '2001-06-15' 
WHERE user_id = 1;

-- ========== SELECT OPERATIONS ==========

-- Basic select operations
SELECT * FROM users;
SELECT * FROM accounts;
SELECT * FROM transactions;

-- Select users with their accounts
SELECT 
    u.first_name, 
    u.last_name, 
    a.account_number, 
    a.balance 
FROM users u
JOIN accounts a ON u.user_id = a.user_id;

-- Select completed transactions
SELECT * FROM transactions WHERE status = 'completed';

-- Select transactions above certain amount
SELECT * FROM transactions WHERE amount > 1000.00;


