import React from 'react';
import {
    AsyncStorage
} from 'react-native';
export default class DataRepository{
    fetchRepository(url){
        return new Promise((resolve,reject)=>{
            this.fetchLocalRepository(url)
                .then(result=>{
                    if(result){
                        resolve(result);
                    }else{
                        this.fetchNetRepository(url)
                            .then(result=>{
                                resolve(result);
                            })
                            .catch(e=>{
                                resolve(e);
                            })
                    }
                })
                .catch(e=>{
                    this.fetchNetRepository(url)
                        .then(result=>{
                            resolve(result);
                        })
                        .catch(e=>{
                            resolve(e);
                        })
                })
        })
    }
    fetchLocalRepository(url){
        return new Promise((resolve,error)=>{
            AsyncStorage.getItem(url,(error,result)=>{
                if(!error){
                    try{
                        resolve(JSON.parse(result));
                    }catch(e){
                        reject(e);
                    }
                }else{
                    reject(error);
                }
            })
        })
    }
   fetchNetRepository(url){
       return new Promise((resolve, reject) => {
           fetch(url)
               .then(response=>response.json())
               .then(result=>{
                   if(!result){
                       reject(new Error('Data is null'))
                       return;
                   }
                   resolve(result.items);
                   this.saveRepository(url,result.items);
               })
               .catch(error=>{
                   reject(error);
               })
           })
       }
       saveRepository(url,items,callBack){
           if(!url || !items) return;
           let wrapData = {items:items,update_data: new Date().getTime()}
           AsyncStorage.setItem((url,JSON.stringify(wrapData),callBack))
    }
    /*
    longTime数据的时间戳
     */
    checkData(longTime){
        let cDate = new Date();
        let tDate = new Date();
        tDate.setTime(longTime);
        if(cDate.getMonth() !== tDate.getMonth())
            return false;
        if(cDate.getDay() !== tDate.getDay())
            return false;
        if(cDate.getHours() !== tDate.getHours())
             return false;
        return true;

    }

}
