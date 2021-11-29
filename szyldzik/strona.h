const char STRONA[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
     <style> body{ opacity:0; }</style>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Szyldzikowy LED Manager</title>

    <link rel='icon' type="image/png" sizes="32x32" href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAAAAXNSR0IArs4c6QAAAddQTFRFAAAAAAAAgICAqqqqqqqqpKSkxMTEnp6ew8PDyMjI0NDQmpqavr6+1tbWp6enycnJ2traqamp4+Pjp6enpaWl2trauLi419fX4ODg0tLS1tbW5eXl1NTU5eXl19fX4uLiAA7/ABr/ACn/ADb/AET/AFD/AF7/AGv/AHn/AIX/AIb/AIj/AJP/AJT/AKH/AKL/AK7/ALr/ALz/AMj/AMn/AMr/ANX/ANb/ANf/AOT/AO//APH/APz+AP39AP8DAP8QAP8dAP8qAP84AP9EAP9TAP9fAP9tAP95AP+IAP+VAP+iAP+vAP+wAP+xAP+8AP++AP/KAP/LAP/XAP/YAP/kAP/lAP/xAP/zAQL/C/8ADQD/GP8AGQD/JP8AKAD/NQD/QP8AQgD/SfHyTgD/Tv8AWv8AagD/c6vzdf8AdvXJdwD/gwD/g/8AhfmgjZX2j/8AmnzTnwD/p9tdrQD/tc71uQD/uf8AxP8A0nHu0v8A4gD/453b5Njl6Ojo61dt7HoY7eTl7kJ27wD/7+/v8IBN9vrK+Pj4+fn5+vr6+v8A+wD/+/v7/Pz8/f39/v7+/wAA/wAf/wBi/wCY/wCk/wDN/wDZ/xMA/0kA/4wA/8EA/84A//YA////wQpqTwAAACB0Uk5TAAEGBgkOGiovRkdMU1hibXR8foaLi5ChtsvS1N3z/PyuEwNFAAABHklEQVQ4y32T03KEQRBGN7ZtO5tsbNvOxrZtWxs752HzAP9O9+WcU93VU1/rdJqyx0snlS8QJgnwCQI3cfElCa7wfUywNOD35xErJb/m8vZPmGALW9u7ggAzC8tr+Kh4CAcjE5PqBhZQ3Ns/qBagorystIR7BfeHmuqqykVclA2aG+rragEOrc3yse7O9taWxlkAGw13hKzcvIIiY1dHW0sT5xrhiiR9qiE9Mycvv9B4QpBGcAam4xP1KYa0jGyzmwYAEBsXn5AMdub38GMpMio6ZoMHxaI3DPT1hEdIXzk+OjwEDmphfm5qBZOKe7Kzub4qpuHubA/cBOH9Y19oYAmvb1LiAzl9AXcp8c9H4k3Bk8h1oYC3eNceOGkf/wGyTHTQ4Wyt3gAAAABJRU5ErkJggg=='>
    <link rel='shortcut icon' type="image/png" sizes="32x32" href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAAAAXNSR0IArs4c6QAAAddQTFRFAAAAAAAAgICAqqqqqqqqpKSkxMTEnp6ew8PDyMjI0NDQmpqavr6+1tbWp6enycnJ2traqamp4+Pjp6enpaWl2trauLi419fX4ODg0tLS1tbW5eXl1NTU5eXl19fX4uLiAA7/ABr/ACn/ADb/AET/AFD/AF7/AGv/AHn/AIX/AIb/AIj/AJP/AJT/AKH/AKL/AK7/ALr/ALz/AMj/AMn/AMr/ANX/ANb/ANf/AOT/AO//APH/APz+AP39AP8DAP8QAP8dAP8qAP84AP9EAP9TAP9fAP9tAP95AP+IAP+VAP+iAP+vAP+wAP+xAP+8AP++AP/KAP/LAP/XAP/YAP/kAP/lAP/xAP/zAQL/C/8ADQD/GP8AGQD/JP8AKAD/NQD/QP8AQgD/SfHyTgD/Tv8AWv8AagD/c6vzdf8AdvXJdwD/gwD/g/8AhfmgjZX2j/8AmnzTnwD/p9tdrQD/tc71uQD/uf8AxP8A0nHu0v8A4gD/453b5Njl6Ojo61dt7HoY7eTl7kJ27wD/7+/v8IBN9vrK+Pj4+fn5+vr6+v8A+wD/+/v7/Pz8/f39/v7+/wAA/wAf/wBi/wCY/wCk/wDN/wDZ/xMA/0kA/4wA/8EA/84A//YA////wQpqTwAAACB0Uk5TAAEGBgkOGiovRkdMU1hibXR8foaLi5ChtsvS1N3z/PyuEwNFAAABHklEQVQ4y32T03KEQRBGN7ZtO5tsbNvOxrZtWxs752HzAP9O9+WcU93VU1/rdJqyx0snlS8QJgnwCQI3cfElCa7wfUywNOD35xErJb/m8vZPmGALW9u7ggAzC8tr+Kh4CAcjE5PqBhZQ3Ns/qBagorystIR7BfeHmuqqykVclA2aG+rragEOrc3yse7O9taWxlkAGw13hKzcvIIiY1dHW0sT5xrhiiR9qiE9Mycvv9B4QpBGcAam4xP1KYa0jGyzmwYAEBsXn5AMdub38GMpMio6ZoMHxaI3DPT1hEdIXzk+OjwEDmphfm5qBZOKe7Kzub4qpuHubA/cBOH9Y19oYAmvb1LiAzl9AXcp8c9H4k3Bk8h1oYC3eNceOGkf/wGyTHTQ4Wyt3gAAAABJRU5ErkJggg=='>

    <link rel="preload" href="https://cdn.jsdelivr.net/npm/bulma@0.9.3/css/bulma.min.css" as="style">
    <link rel="preload" href="https://cdn.jsdelivr.net/npm/bulma@0.9.3/css/bulma.min.css" as="style">
    <link rel="preload" href="https://cdn.jsdelivr.net/npm/@creativebulma/bulma-divider@1.1.0/dist/bulma-divider.min.css" as="style">
    <link rel="preload" href="https://fonts.googleapis.com/css2?family=Oxygen&display=swap" as="style">
    <link rel="preload" href="https://cdn.jsdelivr.net/npm/@jaames/iro" as="script">

    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.3/css/bulma.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma-prefers-dark@0.1.0-beta.0/css/bulma-prefers-dark.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/@creativebulma/bulma-divider@1.1.0/dist/bulma-divider.min.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Oxygen&display=swap">
    <script src="https://cdn.jsdelivr.net/npm/@jaames/iro"></script>

    <style>
        body {
            font-family: 'Oxygen', sans-serif;
        }
        footer {
            background: transparent !important;
        }
        .tag {
            border-radius: 25px !important;
        }
        .container {
            max-width: 50em !important;
        }
        #kolo {
            border: 0.1em solid rgba(0,0,0,0.15);
        }

        .button {
            border: none;
            box-shadow: 0 1px 2px rgba(0,0,0,0.15) !important;
            transition: box-shadow 0.1s ease-in-out;
        }
        .button:hover {
            box-shadow: 0 5px 15px rgba(0,0,0,0.5) !important;
        }

        .rgbwolna {
            color: white !important;
            text-shadow: 0 0 6px black !important;
            background: linear-gradient(90deg, red, lime, turquoise) !important;
        }
        .rgbszybka {
            color: white !important;
            text-shadow: 0 0 6px black !important;
            background: linear-gradient(90deg, red, orange, yellow, green, blue, indigo, violet) !important;
        }
        .ognisko {
            color: white !important;
            text-shadow: 0 0 6px black !important;
            background: linear-gradient(90deg, orange, red, yellow) !important;
        }
        .ocean {
            color: white !important;
            text-shadow: 0 0 6px black !important;
            background: linear-gradient(90deg, aqua, blue, turquoise) !important;
        }
        .las {
            color: white !important;
            text-shadow: 0 0 6px black !important;
            background: linear-gradient(90deg, lime, green, lawngreen) !important;
        }
    </style>
</head>

<body>
    <section class="section">
        <div class="container">
            <h1 class="title has-text-weight-normal has-text-centered">
                <strong class="has-text-weight-bold">Szyldzikowy</strong>
                <span>
                    <span class="has-text-danger-dark">L</span><span class="has-text-success-dark">E</span><span class="has-text-info-dark">D</span>
                </span>
                Manager
            </h1>
            <form action="/form" method="post">
                <div class="columns is-centered is-mobile is-multiline">
                    <div class="column is-centered is-narrow has-backround-grey">
                        <p class="divider mb-3">
                            Własny kolor
                        </p>
                        <p class="subtitle has-text-centered mb-3">
                            <strong class="tag is-size-4" id="current_color">@@color@@</strong>
                        </p>
                        <div class="wheel" id="koloKolorow"></div>
                        <button class="button is-fullwidth is-rounded mt-3" id="kolo" name="color" type="submit" value="r255g255b255">Ustaw kolor</button>
                    </div>
                    <div class="column">
                        <p class="divider">
                            Kolory
                        </p>
                        <div class="columns is-multiline is-mobile">
                            <div class="column">
                                <button class="button is-fullwidth is-rounded is-dark" name="color" type="submit" value="wyłączony">Wyłącz</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:white;color:black;border:0.1em solid grey" name="color" type="submit" value="r255g255b255">Biały</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:red;color:white" name="color" type="submit" value="r255g000b000">Czerwony</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:#0000FF;color:white" name="color" type="submit" value="r000g000b255">Granatowy</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:#00BB00;color:white" name="color" type="submit" value="r000g255b000">Zielony</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:#FFFF00;color:black" name="color" type="submit" value="r255g180b000">Żółty</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:orange;color:black" name="color" type="submit" value="r255g032b000">Pomarańczowy</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:#00FF88;color:black" name="color" type="submit" value="r000g255b255">Turkusowy</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:#FF00FF;color:white" name="color" type="submit" value="r255g000b255">Magenta</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:#88FF00;color:black" name="color" type="submit" value="r135g255b000">Limonkowy</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:#0088FF;color:white" name="color" type="submit" value="r000g120b255">Niebieski</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:#8800FF;color:white" name="color" type="submit" value="r125g000b255">Fioletowy</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded" style="background:#FF0088;color:white" name="color" type="submit" value="r255g000b135">Karmazynowy</button>
                            </div>
                        </div>
                        <p class="divider">
                            Sekwencje
                        </p>
                        <div class="columns is-multiline is-mobile">
                            <div class="column">
                                <button class="button is-fullwidth is-rounded rgbwolna" name="color" type="submit" value="sekwencja RGB (wolna)">🌈 RGB (wolne)</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded rgbszybka" name="color" type="submit" value="sekwencja RGB (szybka)">🌈 RGB (szybkie)</button>
                            </div>
                            <!--<div class="column">
                                <button class="button is-fullwidth is-rounded ognisko" name="color" type="submit" value="sekwencja Ognisko">🔥 Ognisko</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded ocean" name="color" type="submit" value="sekwencja Ocean">🌊 Ocean</button>
                            </div>
                            <div class="column">
                                <button class="button is-fullwidth is-rounded las" name="color" type="submit" value="sekwencja Las">🌲 Las</button>
                            </div>-->
                        </div>
                    </div>
                </div>
            </form>
        </div>
        <br>
    </section>
    <footer class="footer has-text-centered mt-5">
        <p class="has-text-weight-light mb-3">
            - 28.11.2021 -
        </p>
        <p class="is-size-5">
            Dla <i>najlepszej</i> adminki <strong>Karoliny</strong>
            z okazji <strong>18</strong> urodzin
            od admina <strong>Roberta</strong>
        </p>
        <p class="is-size-5 has-text-weight-bold">
            Wszystkiego dobrego - damy radę 😊!
        </p>
        <p class="has-text-dark-grey mt-3">
            LED Manager 1.0 by revoxhere 2021
            <br><small class="has-text-grey">
              <a href="/reset">Reset ustawień</a>
              &bull;
              IP: <a href="http://@@IP_ADDR@@"><strong>@@IP_ADDR@@</strong></a>
            </small>
        </p>
    </footer>
</body>
<script>
let przycisk = document.getElementById("kolo");
let aktualny_kolor = document.getElementById("current_color");
aktualny_kolor_str = aktualny_kolor.innerHTML + '';

let kolor_hex = "#FFFFFF";
let kolor_rgb = "rgb(255, 255, 255)";

function pad(n) {
    if (n < 10)
        return "00" + n;
    else if (n < 100)
        return "0" + n;
    return n;
}

function rgb_to_hex(rgb) {
    let sep = rgb.indexOf(",") > -1 ? "," : " ";
    rgb = rgb.substr(4).split(")")[0].split(sep);

    let r = (+rgb[0]).toString(16),
        g = (+rgb[1]).toString(16),
        b = (+rgb[2]).toString(16);

    if (r.length == 1)
        r = "0" + r;
    if (g.length == 1)
        g = "0" + g;
    if (b.length == 1)
        b = "0" + b;

    return "#" + r + g + b;
}

function get_contrast(hex) {
    console.log(hex);
    if (hex == "#NaNNaNNaN" || hex == "#ffffff") return "#000000";

    let threshold = 130;
    let colorBrightness = ((hexToRed(hex) * 299) + (hexToGreen(hex) * 587) + (hexToBlue(hex) * 114)) / 1000;

    function cleanHex(h) { return (h.charAt(0) == "#") ? h.substring(1, 7) : h }

    function hexToRed(h) { return parseInt((cleanHex(h)).substring(0, 2), 16) }

    function hexToGreen(h) { return parseInt((cleanHex(h)).substring(2, 4), 16) }

    function hexToBlue(h) { return parseInt((cleanHex(h)).substring(4, 6), 16) }

    return (colorBrightness > threshold) ? "#000000" : "#ffffff"
}

try {
    let red = aktualny_kolor_str.substring(1, 4);
    let green = aktualny_kolor_str.split("g")[1].substring(0, 3);
    let blue = aktualny_kolor_str.split("b")[1].substring(0, 3);

    kolor_rgb = `rgb(${parseInt(red)}, ${parseInt(green)}, ${parseInt(blue)})`;
    console.log("RGB: " + kolor_rgb);
    kolor_hex = rgb_to_hex(kolor_rgb);
    console.log("HEX: " + kolor_hex);

    kolor_nazwa = kolor_hex;
} catch (err) {
    console.log(`Blad ustawiania koloru: ${err}`);
    kolor_nazwa = aktualny_kolor_str;
}

let colorWheel = new iro.ColorPicker("#koloKolorow", {
    color: kolor_hex,
    layout: [{
        component: iro.ui.Wheel,
        options: {
            wheelLightness: false,
            wheelAngle: 0,
            wheelDirection: "clockwise"
        }
    }, {
        component: iro.ui.Slider,
        options: {
            sliderType: 'value'
        }
    }, ]

});

aktualny_kolor.innerHTML = kolor_nazwa;
aktualny_kolor.style.background = kolor_rgb;
aktualny_kolor.style.color = get_contrast(rgb_to_hex(kolor_rgb));

przycisk.style.background = kolor_rgb;
przycisk.style.color = get_contrast(rgb_to_hex(kolor_rgb));

colorWheel.on('color:change', function(color, changes) {
    let kolor = colorWheel.color.rgb;
    let kolor_rgb = `rgb(${parseInt(kolor.r)}, ${parseInt(kolor.g)}, ${parseInt(kolor.b)})`;

    przycisk.value = `r${pad(kolor.r)}g${pad(kolor.g)}b${pad(kolor.b)}`;
    przycisk.style.background = kolor_rgb;
    przycisk.style.color = get_contrast(rgb_to_hex(kolor_rgb));
});
</script>

<script>
  window.onload = function() {setTimeout(function(){document.body.style.opacity="100";},100);};
</script>

</html>
)=====";
