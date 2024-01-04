import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    def double(salary):
        return salary * 2
    
    employees['bonus'] = employees['salary'].apply(double)
    
    return employees