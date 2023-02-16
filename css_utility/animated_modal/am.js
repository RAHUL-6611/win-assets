
buttons = document.querySelectorAll('.button');
modalCont = document.getElementById('modal-container');
body = document.body;
console.log(body)   

buttons.forEach(button => {
    button.addEventListener('click',(e)=>{
        console.log(e.target);
        bid = e.target.getAttribute('id');
        modalCont.classList.remove('out');
        modalCont.classList.add(bid);
        body.classList.add('modal-active');
    })
})

modalCont.addEventListener('click',(e)=>{
    e.target.classList.add('out');
    body.classList.remove('modal-active')
})