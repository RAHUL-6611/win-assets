import React from 'react'

export default function Navbar({value,search,setValue,setSearch}) {
  return (
    <div className='flex shadow-[rgba(7,_65,_210,_0.1)_0px_9px_30px] h-16 w-full justify-around  flex-wrap pt-3'>
      <h1 className='flex-initial w-32'>hello world</h1>
      <div className='box-border   h-10 w-96 pl-7 rounded-full     bg-yellow-500 shadow-lg bg-yellow-500/50'>
      <label htmlFor='dropdown '>
        <select className='focus:outline-none focus:border-y-2  focus:border-sky-700   appearance-none  font-semibold text-base		 text-white bg-yellow-500 shadow-lg bg-yellow-500/50 h-8   ' onChange={(e) => setValue(e.target.value)} value={value}>
          <option value='recipe'>Search Recipe</option>
          <option value='menuItems'>Find Menu Items</option>
          <option value='ingredients'>Find By Ingredients</option>
        </select>
      </label>
      <input className=' h-8 focus:outline-none  focus:border-y-2  focus:border-sky-700 text-base font-semibold text-white placeholder:text-white pl-4 mt-1 bg-yellow-500 shadow-lg bg-yellow-500/50'  placeholder='Search recipes '  type='text' value={search} onChange={(e) => setSearch(e.target.value)}></input>
      </div>
      
      <h1 className=''>hello world</h1>
      <h1 className=''>hello world</h1>

    </div>
  )
}
