import React from 'react'

export default function ProgressTaste({item}) {
    const containerStyles = {
        height: 20,
        width: '70%',
        borderRadius: 50,
      }
    
      const fillerStyles = {
        height: '100%',
        width: `${item>100?100:item}%`,
        backgroundColor:"rgb(251 191 36)",
        borderRadius: 'inherit',
        textAlign: 'right',
        transition: 'width 1s ease-in-out'
      }
    
      const labelStyles = {
        padding: 5,
        color: 'white',
        fontWeight: 'bold'
      }
  return (
    <div>

  <div className='  pt-5 mt-1 '>
    <div className=' w-72 mr-40  ' style={containerStyles} >
    <div  style={fillerStyles}>
    <span style={labelStyles}>{`${item}%`}</span>
      </div> 
  </div>
  </div>
  </div>
 )
  }
