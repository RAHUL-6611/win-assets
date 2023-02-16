import React, { useState } from 'react'

export default function RecipeCalculator({item,detailData }) {
    // const kk= detailData?.extendedIngredients.map((item)=>item?.measures?.metric?.amount)
    const loo = item?.measures?.metric?.amount
    // console.log(loo)
    const[itemAm,setItemAm] = useState(loo)
   console.log(itemAm)
   const updateAmount = ()=>{
    setItemAm(itemAm*2)
   }

    return (
        <div>
                <div  className=" flex mt-10 flex-wrap  flex-col  items-center justify-around	 h-56 w-56  rounded-2xl  shadow-[inset_-12px_-8px_40px_#46464620]  shadow-yellow-400" >
                  <div  className=''>
                    <img className="max-w-[100px] max-h-[100px]" src={`https://spoonacular.com/cdn/ingredients_100x100/${item.image}`}></img>
                    </div>
                    <div className="">
                      
                        <p>{item?.name}</p>
                        <p>{itemAm + "  " + item?.measures?.metric?.unitShort}</p>
                    </div>
                    <div>
                    <button onClick={()=>updateAmount()}  className="bg-transparent mt-1 hover:bg-yellow-400 text-yellow-500 font-semibold hover:text-white py-2 px-6 border border-yellow-500 hover:border-transparent rounded-lg">
                        Substitute
                    </button>
                    </div>
               
            </div>
        </div>
    )
}
