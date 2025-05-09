const express = require("express");
const { spawn } = require("child_process");
const path = require("path");

const app = express();
app.use(express.static(path.join(__dirname, "public")));
app.use(express.json());

app.post("/censor", (req, res) => {
    const text = req.body.text;
    
    if (!text) return res.json({ censoredText: "No input provided" });

    const process = spawn("./censor");

    let output = "";
    process.stdout.on("data", (data) => {
        output += data.toString();
    });

    process.stderr.on("data", (data) => console.error("Error:", data.toString()));

    process.on("close", (code) => {
        if (code !== 0) return res.json({ error: "C++ execution failed" });
        res.json({ censoredText: output.trim() });
    });

    process.stdin.write(text + "\n");
    process.stdin.end();
});

app.listen(3000, () => console.log("Server running at http://localhost:3000"));
