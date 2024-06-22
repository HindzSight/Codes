import React, { useState , useEffect} from "react"
import TodoInput from "./components/TodoInput"
import TodoList from "./components/TodoList"

function App() {

  const [todos,setTodos] = useState([])
  const [todoValue, setTodoValue] = useState('')

    function persistTodos(todos2){
      localStorage.setItem('todos', JSON.stringify({ todos : todos2}))  
    } 

    function addTodo (todo) {
      persistTodos([...todos, todo])
      setTodos([...todos, todo])
    }

    function deleteTodo (index) {
      const newTodos = todos.filter((todo, i) => i !== index)
      persistTodos(newTodos)
      setTodos(newTodos)
    }

    function editTodo (index) {
      const valueToEdit = todos[index]
      setTodoValue(valueToEdit)
      deleteTodo(index)
    }

    useEffect(() => {
      if(!localStorage) return
      let localTodos = localStorage.getItem('todos')
      if(!localTodos) return

      localTodos = JSON.parse(localTodos).todos
      setTodos(localTodos)
    }, []) 

  return (
    <>
      <TodoInput 
      todoValue={todoValue}
      setTodoValue={setTodoValue}
      addTodo={addTodo} />
      <TodoList
      deleteTodo={deleteTodo}
      editTodo={editTodo}
      todos={todos} />
    </>
  )
}

export default App
