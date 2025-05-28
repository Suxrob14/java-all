<button onclick="increase()">Нажми</button>
<p id="counter">0</p>

<script>
let count = 0;
function increase() {
    count++;
    document.getElementById("counter").innerText = count;
}
</script>
