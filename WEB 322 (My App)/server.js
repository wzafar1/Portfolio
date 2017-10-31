/*********************************************************************************
*  WEB322 – Assignment 03
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part *  of this assignment has been copied manually or electronically from any other source 
*  (including 3rd party web sites) or distributed to other students.
* 
*  Name: Wahab Zafar Student ID: 106939168 Date: 16/10/2017
*
*  Online (Heroku) Link: https://vast-bastion-79580.herokuapp.com/
*
********************************************************************************/


var express = require('express');
var path = require('path');
const exphbs = require('express-handlebars');
const bodyParser = require('body-parser');
var app = express();
var dataService = require("./data-service.js")
var HTTP_PORT = process.env.PORT || 8080;


app.use(express.static("public"));

app.use(bodyParser.urlencoded({ extended: true }));

app.engine(".hbs", exphbs({
  extname: ".hbs",
  defaultLayout: 'layout',
  helpers: {
    equal: function (lvalue, rvalue, options) {
      if (arguments.length < 3)
        throw new Error("Handlebars Helper equal needs 2 parameters");
      if (lvalue != rvalue) {
        return options.inverse(this);
      } else {
        return options.fn(this);
      }
    }
  }
}));
app.set("view engine", ".hbs");

dataService.initialize().then((data)=>{
    app.listen(HTTP_PORT,listening);
}).catch((err)=>{
    res.json({message:err});
});

function listening(){
    console.log("Express http server listening on: "+HTTP_PORT);
}

// setup a 'route' to listen on the default url path (htmll page)
app.get("/",(req,res)=>{
  res.render("home"); //
}); 

// setup a 'route' to listen on the second url path (htmll page)
app.get("/about", (req,res)=>{
  res.render("about"); 
});

//setup a 'route' to display employee records based on different parameters provided or none
app.get("/employees", (req,res)=>{
    if(req.query.status){
      dataService.getEmployeesByStatus(req.query.status).then((data)=>{
        res.render("employeeList", { data: data, title: "Employees" }); 
    }).catch(()=>{
        res.render("employeeList", { data: {}, title: "Employees" }); 
    });
    }else if(req.query.department){       // Display employees record by department id
      dataService.getEmployeesByDepartment(req.query.department).then((data)=>{
        res.render("employeeList", { data: data, title: "Employees" });
    }).catch(()=>{
      res.render("employeeList", { data: {}, title: "Employees" }); 
    });
    }else if (req.query.manager){         // Display employees record by manager id
      dataService.getEmployeesByManager(req.query.manager).then((data)=>{
        res.render("employeeList", { data: data, title: "Employees (Managers)" });
    }).catch((err)=>{
        res.render("employeeList", { data: {}, title: "Employees (Managers)" });
    });
    }else{                               // If none from above, display all the employees records
      dataService.getAllEmployees().then((data)=>{
        res.render("employeeList", { data: data, title: "Employees" });
    }).catch((err)=>{
       res.render("employeeList", { data: {}, title: "Employees" });
    });
    }
  });

  // Display employee based on id provided
  app.get("/employee/:eNum",(req,res)=>{
    dataService.getEmployeeByNum(req.params.eNum).then((data)=>{
      res.render("employee", { data: data});
    }).catch((err)=>{
      res.status(404).send("Employee Not Found");
    });
  });

  // Display manager based on id provided
  app.get("/managers",(req,res)=>{ 
    dataService.getManagers().then((data)=>{
      res.render("employeeList", { data: data, title: "Employees (Managers)" });
    }).catch(()=>{
      res.render("employeeList", { data: {}, title: "Employees (Managers)" });
    });
  });

  // Display departments based on id provided
  app.get("/departments",(req,res)=>{ 
    dataService.getDepartments().then((data)=>{
      res.render("departmentList", { data: data, title: "Departments" });
    }).catch(()=>{
      res.render("departmentList", { data: {}, title: "Departments" });;
    });
  });
  
  // Add new employee
  app.get("/employees/add", (req,res) => {
    res.render("addEmployee");
  });

  app.post("/employees/add", (req, res) => {
    dataService.addEmployee(req.body).then((data) => {
      res.redirect("/employees");
    });
  });

  app.post("/employees/update", (req, res) => {
    dataService.addEmployee(req.body).then((data) => {
      res.redirect("/employees");
    });
  });


//Return error message - put at the end for use() function
app.use((req,res)=>{
  res.status(404).send("<h1>" + "404 Page Not Found" + "</h1>" + "</br>"+"The requested URL " + req.path + " was not found on server");
  });
  // req.path displays the request