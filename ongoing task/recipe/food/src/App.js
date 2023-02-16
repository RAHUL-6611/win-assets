import React, { useEffect, useState } from 'react'
import {
  BrowserRouter as Router,
  Routes,
  Route,
} from "react-router-dom";
import Navbar from './Navbar';
import Body from './Body';
import axios from 'axios'
import DetailsRecipe from './DetailsRecipe';


export default function App() {
  const [data, setData] = useState([]);
  const [search, setSearch] = useState('');
  const [value, setValue] = useState('ingredients');
  const [page, setPage] = useState(2);
  const [menuItemsPage,setMenuItemsPage] = useState(2);
  const[ingredientsPage,setIngredientsPage] = useState(2)


  const fetchMoreData = () => {
    let Api = `https://api.spoonacular.com/`
    let searchRecipe = Api + `recipes/complexSearch?query=${search}&number=${page}&apiKey=b9a6b0d4177f4849b76aa0f5b64d1be2`
    let searchMenuItems = Api + `food/menuItems/search?query=${search}&number=${menuItemsPage}&apiKey=b9a6b0d4177f4849b76aa0f5b64d1be2`
    let findByIngredients = Api + `recipes/findByIngredients?ingredients=${search}&number=${ingredientsPage}&apiKey=b9a6b0d4177f4849b76aa0f5b64d1be2`


    if (value === "recipe") {
      axios.get(searchRecipe).then(resp => {
        setData(resp.data.results)
       setPage(page+4)
      });
    } else if (value === 'menuItems') {
      axios.get(searchMenuItems).then(resp => {
        setData(resp.data?.menuItems)
        setMenuItemsPage(menuItemsPage+4)

      });
    } else {
      axios.get(findByIngredients).then(resp => {
        setData(resp.data)
        setIngredientsPage(ingredientsPage+4)

      });
    }
  }


  useEffect(() => {
    const timer = setTimeout(async () => {
      if (search.length === 0) {
        setData([]);
        setPage(4)
        setMenuItemsPage(4)
        setIngredientsPage(4)

     
      }
      if (search.length >= 1) {
        await fetchMoreData()
      }
    }, 500);
    return () => {
      clearTimeout(timer);
    };
  }, [search, value]);
 

  return (
    <div>
      
      {
        <Router>
          <Navbar value={value} setValue={setValue} search={search} setSearch={setSearch} />
          <Routes>
          <Route path='/' element={<Body data={data} fetchMoreData = {fetchMoreData}  />}></Route> 
          <Route path='/DetailsRecipe'  element={<DetailsRecipe   />}   ></Route>
          </Routes>
        </Router>
      }
    </div>
  )
}
