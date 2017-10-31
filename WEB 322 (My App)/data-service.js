var employees = [];
var departments= [];
var empCount = 0;
var fs = require("fs");

module.exports.initialize = ()=>{
    return new Promise((resolve,reject)=>{
        fs.readFile("./data/employees.json",(err,data)=>{
            if(err)
                throw new Error("<h1>" + "File Not Found" + "</h1>" + "</br>" + "Please contact the Web Administrator");
            else
            employees=JSON.parse(data);
            empCount=employees.length;
        });
        fs.readFile("./data/departments.json",(err,data)=>{
            if(err)
                throw new Error("<h1>" + "File Not Found" + "</h1>" + "</br>" + "Please contact the Web Administrator");
            else
            departments=JSON.parse(data);   
        });
        try{
            resolve();
        }catch(ex){
            reject("<h1>" + "File Not Found" + "</h1>" + "</br>" + "Please contact the Web Administrator")
        }
    });
};

module.exports.getAllEmployees = ()=>{
    return new Promise((resolve,reject)=>{
        if(employees.length>0){
            resolve(employees); // Display the all employees by sending the employees array back to caller (which is in server.js)
        }else
            reject("No Employee record found");
    });
}

module.exports.getEmployeesByStatus=(status)=>{
    var EmpSt = [];   // A temporary arry used to stored the matched employees record
     return new Promise((resolve,reject)=>{
        var index=0; // A new var to keep track of number of records found
        for(var i=0;i<employees.length;i++){
            if(employees[i].status==status){
                EmpSt[index]=employees[i];
                index++;  
            }
        }            
        if(EmpSt.length>0)  // Only send if record is found (number of entries greater than 0)
        resolve(EmpSt);
        else
        reject("No Employee with status " + status + " found in records");
    });
}

module.exports.getEmployeesByDepartment=(department)=>{
     var Dep = [];  // A temporary arry used to stored the matched departments record
    return new Promise((resolve,reject)=>{
        var index=0;  // A new var to keep track of number of records found
        for(var i=0;i<employees.length;i++){
            if(employees[i].department==department){
                Dep[index]=employees[i];
                index++;  
            }            
        }
        if(Dep.length>0)   // Only send if record is found (number of entries greater than 0)
            resolve(Dep);
        else
            reject("No Department with id " + department + " found in records");
    });
}

module.exports.getEmployeesByManager=(Manager)=>{
    var Mgr = [];   // A temporary arry used to stored the matched employees record under specified Manager
    return new Promise((resolve,reject)=>{
        var index=0;   // A new var to keep track of number of records found
        for(var i=0;i<employees.length;i++){
            if(employees[i].employeeManagerNum==Manager){
                Mgr[index]=employees[i];
                index++;  
            }              
        }        
        if(Mgr.length>0)  // Only send if record is found (number of entries greater than 0)
            resolve(Mgr);
        else
            reject("No Employee under Mgrager with id " + Manager + " found in records");
    });
}

module.exports.getEmployeeByNum=(num)=>{
    var found=1; // A var used to terminate the for loop if record is found
    return new Promise((resolve,reject)=>{
        for(var i=0;i<employees.length && found==1;i++){
            if(employees[i].employeeNum==num){
               resolve(employees[i]);
               found=0;
            }
        }
        if (found==1){
            reject("No Employee with id " + num + " found in records");
        }
});
}

module.exports.getManagers=()=>{
    var IsMgr = [];   // A temporary arry used to stored the matched employees who are Manager
    return new Promise((resolve,reject)=>{
        var index=0;  // A new var to keep track of number of records found
        for(var i=0;i<employees.length;i++){
            if(employees[i].isManager==true){
                IsMgr[index]=employees[i];
                index++;  
            }            
        }            
        if(IsMgr.length>0)  // Only send if record is found (number of entries greater than 0)
            resolve(IsMgr);
        else
            reject("No Employee who is Manager found in records");
    });
}

module.exports.getDepartments=()=>{
    return new Promise((resolve,reject)=>{
        if(departments.length>0)
            resolve(departments);          
        else
            reject("No Department found in records");
    });

}

module.exports.addEmployee = (employeeData) => {
    
    return new Promise((resolve, reject) => {
        empCount=employees.length;
        empCount++;
        employeeData.employeeNum=empCount;
        employees.push(employeeData);
        if (employeeData) 
        {
           resolve();
        }
        else{
           reject("No data returned");
        }
    });
};

module.exports.updateEmployee = (employeeData) => {
    var state=true;
    return new promise ((resolve,reject)=>{
        for(var i=0;i<employees.length && state;i++){
            if(employees[i].employeeNum==employeeData.employeeNum){
                employees[i]=employeeData;
                state=0
            }
        }
        if (state==false){
            resolve();
        }else{
            reject();
        }
    });
}