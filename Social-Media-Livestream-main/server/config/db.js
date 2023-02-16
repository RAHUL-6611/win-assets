const mysql = require("mysql");

const db = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "Rahul1138",
  database: "SocialMedia",
});

module.exports = db;
