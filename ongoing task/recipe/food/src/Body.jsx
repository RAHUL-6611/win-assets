import { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import InfiniteScroll from "react-infinite-scroll-component";
import { MetroSpinner } from "react-spinners-kit";

export default function Body({ data, fetchMoreData}) {
    const [loading, setLoading] = useState(true)
    let navigate = useNavigate();
    const onPushScreen = (index) => {
        let recipeID = {
            index: data[index].id
        }
        console.log(data[index].id)
        navigate('/DetailsRecipe', { state: recipeID })
    }


    return (

        <div >
            <InfiniteScroll
                dataLength={data.length}
                next={fetchMoreData}
                hasMore={true}
                loader={<div className='flex flex-wrap my-10 mx-[510px]' style={{ overflow: "hidden" }}><MetroSpinner
                    size={40} color="#808080"
                    loading={loading} /></div>}
                scrollableTarget="scrollableDiv"
            >
                <div className='flex   flex-wrap justify-around  '>
                    {data?.map((item, index) => (
                        <div key={index} className=' text-center mt-20  w-72 shadow-[rgba(0,_0,_0,_0.4)_0px_30px_90px]   rounded-3xl '>
                            <div className='h-44 relative ml-12'>
                                <img className='object-cover shadow-[rgba(8,_112,_184,_0.7)_0px_30px_90px] shadow-yellow-400 -top-10 absolute h-48 w-48 rounded-full' src={item.image}></img>
                            </div>
                            <div className=' '>
                                <div className=' mb-4 '>
                                    <h1>{item.title}</h1>
                                </div>
                                <div className='mb-6 '>
                                    <button onClick={() => onPushScreen(index)} className="bg-transparent hover:bg-yellow-400 text-yellow-500 font-semibold hover:text-white py-2 px-4 border border-yellow-500 hover:border-transparent rounded-lg">
                                    Recipe Detail
                                    </button>
                                </div>
                            </div>
                        </div>))
                    } </div>

            </InfiniteScroll>
        </div>

    )
}
