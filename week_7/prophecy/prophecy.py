import csv
from cs50 import SQL

db = SQL("sqlite:///roster.db")

db.execute("DELETE FROM students")
db.execute("DELETE FROM houses")
db.execute("DELETE FROM relation")

with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        db.execute("INSERT INTO students (id, student_name) VALUES(?, ?)", row['id'], row['student_name'])
        db.execute("INSERT INTO houses (house_name, house_head) SELECT * FROM (SELECT ?, ?) AS tmp WHERE NOT EXISTS (SELECT * FROM houses WHERE house_name = ? LIMIT 1);", row['house'], row['head'], row['house'])
        db.execute("INSERT INTO relation (student_id, house_id) VALUES(?, (SELECT id FROM houses WHERE house_name = ?))", row['id'], row['house'])

