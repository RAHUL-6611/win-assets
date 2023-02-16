import { useEffect, useState, memo } from "react";
import { useLocation } from 'react-router-dom';
import ProgressBar from "./ProgressBar";
import { MetroSpinner } from "react-spinners-kit";
import axios from 'axios';
import ProgressTaste from "./ProgressTaste";
import Card from "./Card";
import RecipeCalculator from "./RecipeCalculator";

const DetailsRecipe = memo(function DetailsRecipe() {
  let location = useLocation();
  const [detailData, setDetailData] = useState();
  const [nutritionList, setNutritionList] = useState();
  const [loading, setLoading] = useState(true)
  const [taste, setTaste] = useState();
  const [keys, setKeys] = useState();
  const [recipes, setRecipes] = useState();
  const [apiValue, setApiValue] = useState(location.state.index)


  let instructions = `https://api.spoonacular.com/recipes/${apiValue}/information?includeNutrition=false&apiKey=b9a6b0d4177f4849b76aa0f5b64d1be2`
  let nutrition = `https://api.spoonacular.com/recipes/${apiValue}/nutritionWidget.json?&apiKey=b9a6b0d4177f4849b76aa0f5b64d1be2`
  let tasteData = `https://api.spoonacular.com/recipes/${apiValue}/tasteWidget.json?&apiKey=b9a6b0d4177f4849b76aa0f5b64d1be2`
  let similarRecipes = `https://api.spoonacular.com/recipes/${apiValue}/similar?&apiKey=b9a6b0d4177f4849b76aa0f5b64d1be2`

 
  useEffect(() => {
    setLoading(true)
    axios.get(instructions).then(resp => {
      setDetailData(resp.data);
      setLoading(false)
    });
    axios.get(nutrition).then(resp => {
      setNutritionList(resp.data);
      setLoading(false)
    });
    axios.get(similarRecipes).then(resp => {
      setRecipes(resp.data)
      console.log(resp.data)
    });
    const data = async () => {
      await axios.get(tasteData).then(resp => {
        const propertyValues = Object.values(resp.data);
        const propertyKeys = Object.keys(resp.data);
        setTaste(propertyValues)
        setKeys(propertyKeys)
      })
    };
    data();

  }, [apiValue])

  const onPushButton = (index) => {
    let indexRecipe = recipes[index].id
    setApiValue(indexRecipe);
    window.scrollTo({
      top: 0,
      behavior: 'smooth'
    });
  }

  const toTitleCase = (phrase) => {
    return phrase
        .toLowerCase()
        .split(' ')
        .map(word => word.charAt(0).toUpperCase() + word.slice(1))
        .join(' ');
};

console.log(detailData)
  return (
    <div className="">
      <div className="mx-[500px] my-48 absolute" style={{ overflow: "hidden" }}>
        <MetroSpinner  size={40} loading={loading} color="#808080" />
      </div>
      <h1 className="text-center underline decoration-4 decoration-red-700 text-3xl font-medium text-yellow-500 mt-5 font-[cursive]">{detailData?.title}</h1>
      <div className="flex  flex-wrap justify-around   w-11/12 ml-10   p-10 rounded-3xl">
        <img className="object-cover  shadow-[rgba(0,_0,_0,_0.4)_0px_30px_90px] h-96 rounded-3xl w-96" src={detailData?.image}></img>
        <div className="shadow-[inset_-12px_-8px_40px_#46464620]     rounded-2xl pl-4 h-96 w-96 overflow-hidden   hover:overflow-y-scroll">
          <div className="" dangerouslySetInnerHTML={{ __html: detailData?.summary }} ></div>
        </div>
      </div>
      <h1 className="text-center underline decoration-4 decoration-red-700 text-3xl font-medium text-yellow-500 mt-5 font-[cursive]">Follow Steps to prepare {detailData?.title}</h1>
      <div className=" flex flex-wrap justify-around">
        {detailData?.analyzedInstructions[0]?.steps?.map((item, index) => (
          <div className="shadow-[inset_-12px_-8px_40px_#46464620]  h-60 w-72 rounded-3xl shadow-yellow-500  mt-6 p-4 overflow-hidden hover:overflow-y-auto " key={index}>
            <h1>{item.number + ".  " + item.step}</h1>
            <div className="flex flex-wrap w-72 ">
              {item.equipment.map((item, index) => (<div className=" " key={index}><img src={`https://spoonacular.com/cdn/equipment_100x100/${item.image}`}></img><p>{item.name}</p></div>))}
              {item.ingredients.map((item, index) => (<div key={index}><img src={`https://spoonacular.com/cdn/ingredients_100x100/${item.image}`}></img><p>{item.name}</p></div>))}
            </div>
          </div>))}
      </div><br />
      <h1 className="text-center underline decoration-4 decoration-red-700 text-3xl font-medium text-yellow-500 mt-5 font-[cursive]">Ingredients Quantity</h1>
      <h2 className="mt-2 text-center underline text-xl decoration-red-700 font-medium text-yellow-500">For Servings {detailData?.servings}</h2>
      <div className="flex flex-wrap justify-around ">
        {detailData?.extendedIngredients.map((item, index) => (<div>
          <Card item={item} detailData={detailData} index={index} key={`card-${index}`}/>
          <RecipeCalculator item={item} detailData = {detailData}/>
          </div>
          ))}
      </div><br /><br />
      <div className="flex justify-around flex-wrap">
        <div className="  w-96 max-h-[520px] shadow-yellow-500  shadow-[inset_-12px_-8px_40px_#46464620] rounded-2xl ">
          <h1 className="text-center underline decoration-4 decoration-red-700 text-2xl font-medium text-yellow-500 mt-5 font-[cursive] ">Nutrition in {detailData?.title}</h1>
          {nutritionList?.bad.map((item, indx) => (
            <ProgressBar key={indx} title={item.title} completed={item.percentOfDailyNeeds} />
          ))}
        </div>
        <div className="flex  rounded-2xl  shadow-yellow-500  shadow-[inset_-12px_-8px_40px_#46464620]   h-96 w-96 flex-wrap">
        <div className="">
          <h1 className="text-center underline decoration-4 decoration-red-700 text-2xl font-medium text-yellow-500 mt-5 font-[cursive] ">Taste of Dish</h1>
          <div className="flex  ">
            <div className="ml-10 ">
              {keys?.map((item) => <h1 className="mt-5">{toTitleCase(item)}</h1>)}
            </div>
            <div className="pl-10">
              {taste?.map((item) => (<ProgressTaste item={item}  />))}
            </div>
          </div>
        </div>
        </div>
      </div><br /><br />
      <div className="text-center underline decoration-4 decoration-red-700 text-4xl font-medium text-yellow-500 mt-5 font-[cursive] ">
        <h1>Similar Recipes</h1>
      </div>

      <div className='flex   flex-wrap justify-around  '>
        {recipes?.map((item, index) => (
          <div key={index} className=' text-center mt-20  w-72 shadow-[rgba(0,_0,_0,_0.4)_0px_30px_90px]   rounded-3xl '>
            <div className='h-44 relative ml-12'>
              <img className=' shadow-[rgba(8,_112,_184,_0.7)_0px_30px_90px] shadow-yellow-500 -top-10 absolute h-48 w-48 rounded-full' src={`https://spoonacular.com/recipeImages/${item.id}-556x370.${item.imageType}`}></img>
            </div>
            <div className=' '>
              <div className=' mb-4 '>
                <h1>{item.title}</h1>
              </div>
              <div className='mb-6 '>
                <button onClick={() => onPushButton(index)} className="bg-transparent hover:bg-yellow-500 text-yellow-500 font-semibold hover:text-white py-2 px-4 border border-yellow-500 hover:border-transparent rounded-lg">
                  Recipe Detail
                </button>
              </div>
            </div>
          </div>))
        } </div>
    </div>
  )
})
export default DetailsRecipe;